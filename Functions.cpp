/*
	(name header)
*/

#include "GraphType.h"

void GraphType::bfsTraversal(int vertix, vector<int>& bfsSequence) const
{
	if (gSize > 0)
	{
		bfsSequence.push_back(vertix);
		if (gSize > 1)
		{
			int *visited = new int[gSize]();
			visited[vertix] = 2;
			queue<int> bfsQueue;
			int queueCounter = 0;

			do
			{
				if (queueCounter <= gSize)
					queueCounter += graph[vertix].growQueue(bfsQueue, visited);
				
				vertix = bfsQueue.front();

				bfsQueue.pop();
				visited[vertix] = 2;
				bfsSequence.push_back(vertix);

			} while (!bfsQueue.empty());
            
            delete[] visited;
		}
	}
}

