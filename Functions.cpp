/*
	(name header)
*/

#include "GraphType.h"

void GraphType::bfsTraversal(int vertix, vector<int>& bfsSequence) const
{
	if (gSize > 0)
	{
		if (gSize == 1) bfsSequence.push_back(vertix);
		else
		{
			bool *visited = new bool[gSize]();
			visited[vertix] = true;
			queue<int> bfsQueue;
			int queueCounter = 0;
			bfsQueue.push(vertix);

			do
			{
				vertix = bfsQueue.front();

				bfsQueue.pop();

				if (queueCounter < gSize)
					queueCounter += graph[vertix].growQueue(bfsQueue, visited);
				
				
				visited[vertix] = 2;
				bfsSequence.push_back(vertix);

			} while (!bfsQueue.empty());
            
            delete[] visited;
		}
	}
}

