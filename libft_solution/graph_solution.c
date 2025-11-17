#include "libft/libft.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 20
#define MAX_EDGES 200
#define MAX_NODE_ID 1024

typedef struct s_edge
{
	int			u;
	int			v;
	double		weight;
}				t_Edge;

typedef struct s_parent
{
	int			mask;
	int			node_idx;
}				t_Parent;

typedef struct s_solver
{
	double		graph[MAX_NODES][MAX_NODES];
	int			nodes[MAX_NODES];
	int			node_to_idx[MAX_NODE_ID];
	int			num_nodes;
	double		dp[1 << MAX_NODES][MAX_NODES];
	t_Parent	parent[1 << MAX_NODES][MAX_NODES];
	int			start_node[1 << MAX_NODES][MAX_NODES];
	double		max_distance;
	int			best_mask;
	int			best_end_idx;
	bool		best_is_cycle;
}				t_Solver;

void	init_solver(t_Solver *solver)
{
	int	i;
	int	j;

	solver->num_nodes = 0;
	solver->max_distance = 0.0;
	solver->best_mask = 0;
	solver->best_end_idx = 0;
	solver->best_is_cycle = false;
	ft_memset(solver->node_to_idx, -1, sizeof(solver->node_to_idx));
	i = 0;
	while (i < MAX_NODES)
	{
		j = 0;
		while (j < MAX_NODES)
		{
			solver->graph[i][j] = -1.0;
			j++;
		}
		i++;
	}
}

void	add_node(t_Solver *solver, int node_id)
{
	if (node_id >= MAX_NODE_ID)
		return ;
	if (solver->node_to_idx[node_id] == -1)
	{
		if (solver->num_nodes >= MAX_NODES)
			return ;
		solver->node_to_idx[node_id] = solver->num_nodes;
		solver->nodes[solver->num_nodes] = node_id;
		solver->num_nodes++;
	}
}

void	build_graph(t_Solver *solver, t_Edge *edges, int edge_count)
{
	int	i;
	int	u_idx;
	int	v_idx;

	i = 0;
	while (i < edge_count)
	{
		add_node(solver, edges[i].u);
		add_node(solver, edges[i].v);
		i++;
	}
	i = 0;
	while (i < edge_count)
	{
		u_idx = solver->node_to_idx[edges[i].u];
		v_idx = solver->node_to_idx[edges[i].v];
		if (u_idx != -1 && v_idx != -1)
		{
			if (solver->graph[u_idx][v_idx] < edges[i].weight)
			{
				solver->graph[u_idx][v_idx] = edges[i].weight;
				solver->graph[v_idx][u_idx] = edges[i].weight;
			}
		}
		i++;
	}
}

void	init_dp(t_Solver *solver)
{
	int	n;
	int	i;
	int	j;

	n = solver->num_nodes;
	i = 0;
	while (i < (1 << n))
	{
		j = 0;
		while (j < n)
		{
			solver->dp[i][j] = -INFINITY;
			solver->parent[i][j] = (t_Parent){-1, -1};
			solver->start_node[i][j] = -1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		solver->dp[1 << i][i] = 0.0;
		solver->start_node[1 << i][i] = i;
		i++;
	}
	if (n == 1)
	{
		solver->best_mask = 1;
		solver->best_end_idx = 0;
	}
}

void	try_close_cycle(t_Solver *solver, int v_idx, int mask)
{
	int		i;
	int		visited_count;
	int		start_idx;
	double	cycle_dist;

	i = 0;
	visited_count = 0;
	while (i < solver->num_nodes)
	{
		if ((mask >> i) & 1)
			visited_count++;
		i++;
	}
	if (visited_count < 3)
		return ;
	start_idx = solver->start_node[mask][v_idx];
	if (solver->graph[v_idx][start_idx] >= 0)
	{
		cycle_dist = solver->dp[mask][v_idx] + solver->graph[v_idx][start_idx];
		if (cycle_dist > solver->max_distance)
		{
			solver->max_distance = cycle_dist;
			solver->best_mask = mask;
			solver->best_end_idx = v_idx;
			solver->best_is_cycle = true;
		}
	}
}

void	extend_path(t_Solver *solver, int v_idx, int u_idx, int mask)
{
	double	new_dist;
	int		new_mask;

	new_dist = solver->dp[mask][v_idx] + solver->graph[v_idx][u_idx];
	new_mask = mask | (1 << u_idx);
	if (new_dist > solver->dp[new_mask][u_idx])
	{
		solver->dp[new_mask][u_idx] = new_dist;
		solver->parent[new_mask][u_idx] = (t_Parent){mask, v_idx};
		solver->start_node[new_mask][u_idx] = solver->start_node[mask][v_idx];
		if (new_dist > solver->max_distance)
		{
			solver->max_distance = new_dist;
			solver->best_mask = new_mask;
			solver->best_end_idx = u_idx;
			solver->best_is_cycle = false;
		}
	}
}

void	process_neighbors(t_Solver *solver, int v_idx, int mask)
{
	int	n;
	int	start_idx;
	int	u_idx;

	n = solver->num_nodes;
	start_idx = solver->start_node[mask][v_idx];
	u_idx = 0;
	while (u_idx < n)
	{
		if (solver->graph[v_idx][u_idx] >= 0)
		{
			if ((mask >> u_idx) & 1)
			{
				if (u_idx == start_idx)
					try_close_cycle(solver, v_idx, mask);
			}
			else
				extend_path(solver, v_idx, u_idx, mask);
		}
		u_idx++;
	}
}

void	solve(t_Solver *solver)
{
	int	n;
	int	mask;
	int	v_idx;

	n = solver->num_nodes;
	if (n == 0 || n == 1)
		return ;
	mask = 1;
	while (mask < (1 << n))
	{
		v_idx = 0;
		while (v_idx < n)
		{
			if (!isinf(solver->dp[mask][v_idx]))
				process_neighbors(solver, v_idx, mask);
			v_idx++;
		}
		mask++;
	}
}

void	reconstruct_and_print_path(t_Solver *solver)
{
	int			path[MAX_NODES];
	int			path_len;
	int			mask;
	int			v_idx;
	t_Parent	p;

	if (solver->num_nodes == 0)
		return ;
	if (solver->max_distance == 0.0 && solver->num_nodes > 1)
	{
		printf("%d\r\n", solver->nodes[0]);
		return ;
	}
	path_len = 0;
	mask = solver->best_mask;
	v_idx = solver->best_end_idx;
	while (v_idx != -1)
	{
		path[path_len++] = solver->nodes[v_idx];
		p = solver->parent[mask][v_idx];
		mask = p.mask;
		v_idx = p.node_idx;
	}
	v_idx = path_len - 1;
	while (v_idx >= 0)
	{
		printf("%d\r\n", path[v_idx]);
		v_idx--;
	}
	if (solver->best_is_cycle && path_len > 0)
		printf("%d\r\n", path[path_len - 1]);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

bool	parse_parts(char **parts, t_Edge *edge)
{
	int	count;

	count = 0;
	while (parts[count])
		count++;
	if (count != 3)
		return (false);
	edge->u = ft_atoi(parts[0]);
	edge->v = ft_atoi(parts[1]);
	edge->weight = atof(parts[2]);
	return (true);
}

int	read_input(t_Edge *edges)
{
	char	*line;
	int		count;
	char	**parts;
	int		i;

	count = 0;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (count >= MAX_EDGES)
		{
			free(line);
			break ;
		}
		i = 0;
		while (line[i] && line[i] != '\r' && line[i] != '\n')
			i++;
		line[i] = '\0';
		parts = ft_split(line, ',');
		free(line);
		if (parts)
		{
			if (parse_parts(parts, &edges[count]))
				count++;
			free_split(parts);
		}
		line = get_next_line(0);
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	t_Edge edges[MAX_EDGES];
	int edge_count;
	t_Solver *solver;

	if (argc > 1)
	{
		fprintf(stderr, "Usage: %s < input.txt\n", argv[0]);
		return (1);
	}
	edge_count = read_input(edges);
	if (edge_count == 0)
	{
		ft_putstr_fd("Error: No valid input data\n", 2);
		return (1);
	}
	solver = (t_Solver *)malloc(sizeof(t_Solver));
	if (!solver)
	{
		ft_putstr_fd("Failed to allocate memory for solver\n", 2);
		return (1);
	}
	init_solver(solver);
	build_graph(solver, edges, edge_count);
	init_dp(solver);
	solve(solver);
	reconstruct_and_print_path(solver);
	free(solver);
	return (0);
}