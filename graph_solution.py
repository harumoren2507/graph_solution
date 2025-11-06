#!/usr/bin/env python3
"""
最長片道きっぷの旅の実装

可読性・リファクタリング性を上げるために、42Tokyoの各関数25行制限・引数3つまでのコーディング規則を採用しました。
引数の数を3つ以内に制限するために、初期実装の手続き型の実装をクラスベースにリファクタリング

"""

import sys
from collections import defaultdict
from typing import List, Tuple, Dict, Optional


# =======================================
# 入力処理（クラス外部の独立した関数）
# =======================================

def parse_line(line: str) -> Optional[Tuple[int, int, float]]:
    """1行をパースして(駅ID1, 駅ID2, 距離)を返す"""
    cleaned_line = line.strip()
    if not cleaned_line:
        return None
    try:
        parts = cleaned_line.split(',')
        if len(parts) != 3:
            return None
        u, v, weight = int(parts[0]), int(parts[1]), float(parts[2])
        return u, v, weight
    except (ValueError, IndexError):
        return None

def parse_input(lines: List[str]) -> List[Tuple[int, int, float]]:
    """標準入力からエッジリストをパースする"""
    return [edge for line in lines if (edge := parse_line(line)) is not None]


# =======================================
# メインのソルバークラス
# =======================================

class LongestPathSolver:
    """
    ビットマスクDPを用いてグラフの最長経路を計算するソルバー。
    関連する状態とロジックをすべてカプセル化する。
    """

    def __init__(self, edges: List[Tuple[int, int, float]]):
        # グラフ基本情報
        self.graph: Dict[int, Dict[int, float]] = defaultdict(dict)
        self.nodes: List[int] = []
        self.node_to_idx: Dict[int, int] = {}
        self._build_graph(edges)
        self.n = len(self.nodes)

        # DPテーブル
        self.dp: List[List[float]] = []
        self.parent: List[List[Optional[Tuple[int, int]]]] = []
        self.start_node: List[List[int]] = []
        self._initialize_dp()

        # 最長経路の情報
        self.max_distance: float = 0.0
        self.best_mask: int = 0
        self.best_end_idx: int = 0
        self.best_is_cycle: bool = False

    # ----------------------------------------
    # 初期化ヘルパー
    # ----------------------------------------

    def _build_graph(self, edges: List[Tuple[int, int, float]]) -> None:
        """無向グラフを構築し、ノード情報を設定する"""
        nodes_set = set()
        for u, v, weight in edges:
            nodes_set.add(u)
            nodes_set.add(v)
            # 双方向のエッジを追加（より長い距離で上書き）
            if v not in self.graph[u] or self.graph[u][v] < weight:
                self.graph[u][v] = weight
            if u not in self.graph[v] or self.graph[v][u] < weight:
                self.graph[v][u] = weight
        
        self.nodes = sorted(list(nodes_set))
        self.node_to_idx = {node: i for i, node in enumerate(self.nodes)}

    def _initialize_dp(self) -> None:
        """DPテーブルを初期化する"""
        INF = float('-inf')
        self.dp = [[INF] * self.n for _ in range(1 << self.n)]
        self.parent = [[None] * self.n for _ in range(1 << self.n)]
        self.start_node = [[-1] * self.n for _ in range(1 << self.n)]

        for i in range(self.n):
            mask = 1 << i
            self.dp[mask][i] = 0.0
            self.start_node[mask][i] = i
            if self.n == 1:
                self.best_mask = mask
                self.best_end_idx = i

    # ----------------------------------------
    # DP実行ロジック
    # ----------------------------------------

    def _update_dp_state(self, new_mask: int, u_idx: int, new_dist: float) -> None:
        """DPテーブルを新しい距離で更新する"""
        # このメソッドは引数が多い元のupdate_dp_tableの一部を担う
        # prev_mask, v_idx, curr_startは呼び出し側で分かっている
        self.dp[new_mask][u_idx] = new_dist
    
    def _try_close_cycle(self, v_idx: int, mask: int) -> None:
        """訪問済み隣接ノードが始点の場合、閉路を試す"""
        visited_count = bin(mask).count('1')
        if visited_count < 3:
            return

        curr_dist = self.dp[mask][v_idx]
        curr_start_idx = self.start_node[mask][v_idx]
        
        v_node = self.nodes[v_idx]
        start_node = self.nodes[curr_start_idx]

        if start_node in self.graph[v_node]:
            cycle_dist = curr_dist + self.graph[v_node][start_node]
            if cycle_dist > self.max_distance:
                self.max_distance = cycle_dist
                self.best_mask = mask
                self.best_end_idx = v_idx
                self.best_is_cycle = True

    def _extend_path(self, v_idx: int, u_idx: int, mask: int) -> None:
        """未訪問の隣接ノードへパスを伸ばす"""
        curr_dist = self.dp[mask][v_idx]
        curr_start_idx = self.start_node[mask][v_idx]
        
        v_node = self.nodes[v_idx]
        u_node = self.nodes[u_idx]
        
        new_dist = curr_dist + self.graph[v_node][u_node]
        new_mask = mask | (1 << u_idx)

        if new_dist > self.dp[new_mask][u_idx]:
            self._update_dp_state(new_mask, u_idx, new_dist)
            self.start_node[new_mask][u_idx] = curr_start_idx
            self.parent[new_mask][u_idx] = (mask, v_idx)
            
            if new_dist > self.max_distance:
                self.max_distance = new_dist
                self.best_mask = new_mask
                self.best_end_idx = u_idx
                self.best_is_cycle = False

    def _process_neighbors(self, v_idx: int, mask: int) -> None:
        """ある状態(mask, v_idx)から遷移可能なすべての隣人を処理する"""
        v_node = self.nodes[v_idx]
        curr_start_idx = self.start_node[mask][v_idx]

        for u_node in self.graph[v_node]:
            u_idx = self.node_to_idx[u_node]
            is_visited = (mask >> u_idx) & 1
            
            if is_visited:
                if u_idx == curr_start_idx:
                    self._try_close_cycle(v_idx, mask)
            else:
                self._extend_path(v_idx, u_idx, mask)

    def solve(self) -> List[int]:
        """最長経路探索を実行し、結果のパスを返す"""
        if self.n == 0:
            return []
        if self.n == 1:
            return [self.nodes[0]]

        for mask in range(1, 1 << self.n):
            for v_idx in range(self.n):
                # 有効な状態 (mask, v_idx) のみ処理
                if self.dp[mask][v_idx] != float('-inf'):
                    self._process_neighbors(v_idx, mask)
        
        return self._reconstruct_path()

    # ----------------------------------------
    # 経路復元
    # ----------------------------------------

    def _reconstruct_path(self) -> List[int]:
        """DPテーブルの親ポインタを辿って最長経路を復元する"""
        if self.max_distance == 0.0 and self.n > 1:
             # 連結成分が複数ある場合、単一ノードを返す
            return [self.nodes[0]] if self.nodes else []

        path = []
        mask, v_idx = self.best_mask, self.best_end_idx

        while mask is not None and v_idx is not None:
            path.append(self.nodes[v_idx])
            parent_info = self.parent[mask][v_idx]
            if parent_info is None:
                break
            mask, v_idx = parent_info
        
        path.reverse()

        if self.best_is_cycle and len(path) > 0:
            path.append(path[0])
            
        return path

# =======================================
# メイン実行ブロック
# =======================================

def main() -> None:
    """メイン関数"""
    try:
        input_lines = sys.stdin.readlines()
        edges = parse_input(input_lines)
        
        if not edges:
            print("Error: No valid input data", file=sys.stderr)
            sys.exit(1)
            
        solver = LongestPathSolver(edges)
        path = solver.solve()
        
        for node in path:
            print(node, end='\r\n')

    except Exception as e:
        print(f"An unexpected error occurred: {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
