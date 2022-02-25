/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
	if (node == NULL)
		return node;

	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
	queue<UndirectedGraphNode*> q;

	UndirectedGraphNode *copyNode = new UndirectedGraphNode(node->label);

	m[node] = copyNode;
	q.push(node);

	UndirectedGraphNode *temp = nullptr;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		for (auto ngbr : temp->neighbors)
		{
			if (m.find(ngbr) == m.end())
			{
				m[ngbr] = new UndirectedGraphNode(ngbr->label);
				q.push(ngbr);
			}

			m[temp] -> neighbors.push_back(m[ngbr]);
		}
	}

	return m[node];
}


// https://www.interviewbit.com/problems/clone-graph/