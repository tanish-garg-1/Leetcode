class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int mx = 0;
        for (auto &q : queries) mx = max(mx, q[1]);

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(mx + 1);

        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        int n = mx + 1;

        vector<int> seg(4 * (n + 5), 0);

        auto update = [&](auto &&self, int node, int l, int r,
                          int idx, int val) -> void {
            if (l == r) {
                seg[node] = val;
                return;
            }

            int mid = (l + r) >> 1;

            if (idx <= mid)
                self(self, node * 2, l, mid, idx, val);
            else
                self(self, node * 2 + 1, mid + 1, r, idx, val);

            seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
        };

        auto query = [&](auto &&self, int node, int l, int r,
                         int ql, int qr) -> int {

            if (ql > r || qr < l) return 0;

            if (ql <= l && r <= qr) return seg[node];

            int mid = (l + r) >> 1;

            return max(
                self(self, node * 2, l, mid, ql, qr),
                self(self, node * 2 + 1, mid + 1, r, ql, qr)
            );
        };

        auto it = obstacles.begin();
        auto nxt = next(it);

        while (nxt != obstacles.end()) {
            update(update, 1, 0, n, *it, *nxt - *it);
            ++it;
            ++nxt;
        }

        vector<bool> ans;

        reverse(queries.begin(), queries.end());

        for (auto &q : queries) {

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                auto p = prev(obstacles.upper_bound(x));

                int best = 0;

                if (*p > 0)
                    best = query(query, 1, 0, n, 0, *p - 1);

                best = max(best, x - *p);

                ans.push_back(best >= sz);
            }
            else {

                int x = q[1];

                auto cur = obstacles.find(x);

                auto L = prev(cur);
                auto R = next(cur);

                update(update, 1, 0, n, *L, *R - *L);
                update(update, 1, 0, n, x, 0);

                obstacles.erase(cur);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};