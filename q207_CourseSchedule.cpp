class Solution {
public:
    bool isCyclic(int src, vector<vector<int>>& reqs, vector<bool>& vis, vector<bool>& recPath)
    {
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0; i < reqs.size(); i++)
        {
            int u = reqs[i][1];
            int v = reqs[i][0];

            if (u == src)
            {
                if (!vis[v])
                {
                    if (isCyclic(v, reqs, vis, recPath))
                        return true;
                }
                else if (recPath[v])
                    return true;
            }
        }

        recPath[src] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& reqs) {
       vector<bool> vis(numCourses, false);
       vector<bool> recPath(numCourses, false);

       for(int i = 0; i < numCourses; i++)
        if (!vis[i])
            if (isCyclic(i, reqs, vis, recPath))
                return false;

        return true;
    }
};
