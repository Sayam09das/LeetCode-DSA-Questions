class Solution {
public:
    void dfs(int v, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[v] = true;

        for (int neighbor : rooms[v]) {
            if (!visited[neighbor]) {
                dfs(neighbor, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

        for (bool room : visited) {
            if (!room) {
                return false;
            }
        }

        return true;
    }
};