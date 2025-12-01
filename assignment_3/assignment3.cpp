#include <iostream>
#include <string>

using namespace std;

int tree[4000005][5];
int lazy[4000005][5];
int has_lazy[4000005];
string s;
int n, m;

void push_lazy(int node) {
    if (has_lazy[node] == 0) {
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;

    int temp_tree[5];
    int temp_lazy[5];

    for(int i=0; i<5; i++) {
        temp_tree[i] = 0;
    }

    for(int i=0; i<5; i++) {
        int new_color = lazy[node][i];
        temp_tree[new_color] = temp_tree[new_color] + tree[left][i];
    }

    for(int i=0; i<5; i++) {
        tree[left][i] = temp_tree[i];
    }

    for(int i=0; i<5; i++) {
        temp_lazy[i] = 0;
    }
    for(int i=0; i<5; i++) {
        temp_lazy[i] = lazy[node][lazy[left][i]];
    }
    for(int i=0; i<5; i++) {
        lazy[left][i] = temp_lazy[i];
    }
    has_lazy[left] = 1;

    for(int i=0; i<5; i++) {
        temp_tree[i] = 0;
    }
    for(int i=0; i<5; i++) {
        int new_color = lazy[node][i];
        temp_tree[new_color] = temp_tree[new_color] + tree[right][i];
    }
    for(int i=0; i<5; i++) {
        tree[right][i] = temp_tree[i];
    }

    for(int i=0; i<5; i++) {
        temp_lazy[i] = 0;
    }
    for(int i=0; i<5; i++) {
        temp_lazy[i] = lazy[node][lazy[right][i]];
    }
    for(int i=0; i<5; i++) {
        lazy[right][i] = temp_lazy[i];
    }
    has_lazy[right] = 1;

    for(int i=0; i<5; i++) {
        lazy[node][i] = i;
    }
    has_lazy[node] = 0;
}

void build_tree(int node, int start, int end) {
    for(int i=0; i<5; i++) {
        lazy[node][i] = i;
    }
    has_lazy[node] = 0;

    if (start == end) {
        char c = s[start - 1];
        if (c == 'a') tree[node][0] = 1;
        if (c == 'b') tree[node][1] = 1;
        if (c == 'c') tree[node][2] = 1;
        if (c == 'd') tree[node][3] = 1;
        if (c == 'e') tree[node][4] = 1;
        return;
    }

    int mid = (start + end) / 2;
    build_tree(node * 2, start, mid);
    build_tree(node * 2 + 1, mid + 1, end);

    for(int i=0; i<5; i++) {
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }
}

int find_idx(int node, int start, int end, int k, int color) {
    if (start == end) {
        return start;
    }

    push_lazy(node);

    int mid = (start + end) / 2;
    int left_amount = tree[node * 2][color];

    if (left_amount >= k) {
        return find_idx(node * 2, start, mid, k, color);
    } else {
        return find_idx(node * 2 + 1, mid + 1, end, k - left_amount, color);
    }
}

void update_range(int node, int start, int end, int l, int r, int c1, int c2) {
    if (start > end || start > r || end < l) {
        return;
    }
    if (start >= l && end <= r) {
        int temp_tree[5];
        for(int i=0; i<5; i++) temp_tree[i] = 0;

        int my_map[5];
        for(int i=0; i<5; i++) my_map[i] = i;
        my_map[c1] = c2;

        for(int i=0; i<5; i++) {
            temp_tree[my_map[i]] += tree[node][i];
        }
        for(int i=0; i<5; i++) {
            tree[node][i] = temp_tree[i];
        }

        int new_lazy[5];
        for(int i=0; i<5; i++) {
            new_lazy[i] = my_map[lazy[node][i]];
        }
        for(int i=0; i<5; i++) {
            lazy[node][i] = new_lazy[i];
        }
        has_lazy[node] = 1;
        return;
    }

    push_lazy(node);
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, l, r, c1, c2);
    update_range(node * 2 + 1, mid + 1, end, l, r, c1, c2);

    for(int i=0; i<5; i++) {
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }
}

void print_ans(int node, int start, int end) {
    if (start == end) {
        for(int i=0; i<5; i++) {
            if (tree[node][i] > 0) {
                char c = 'a' + i;
                cout << c;
            }
        }
        return;
    }
    push_lazy(node);
    int mid = (start + end) / 2;
    print_ans(node * 2, start, mid);
    print_ans(node * 2 + 1, mid + 1, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s;

    build_tree(1, 1, n);

    for(int i=0; i<m; i++) {
        int p;
        char c1, c2;
        cin >> p >> c1 >> c2;

        int color1 = c1 - 'a';
        int color2 = c2 - 'a';

        if (color1 == color2) {
            continue;
        }

        int idx = find_idx(1, 1, n, p, color1);
        update_range(1, 1, n, 1, idx, color1, color2);
    }

    print_ans(1, 1, n);
    cout << "\n";

    return 0;
}