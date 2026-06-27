#include <bits/stdc++.h>
using namespace std;

/* ===== 类型别名 ===== */
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

/* ===== 常用宏 ===== */
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

/* ===== 快读快写 ===== */
#define fastio                                                                 \
	ios::sync_with_stdio(false);                                           \
	cin.tie(nullptr)
/* 注意：用了 fastio 就不要和 scanf/printf 混用了 */

/* ===== 调试（可选） ===== */
// #define debug(x) cerr << #x << " = " << (x) << '\n'

/* ===== 常用函数模板 ===== */

// 读一行（含空格）
string readline() {
	string s;
	getline(cin, s);
	return s;
}

// 数组输入
template <typename T> void input(vector<T> &v) {
	for (auto &x : v)
		cin >> x;
}

// 二分查找第一个等于 target 的位置（数组需非降序）
// 返回 1-based 下标；若不存在返回 -1
int bifunc(const vector<int> &list, int target) {
	int l = 0, r = (int)list.size();
	while (l < r) {
		int m = l + (r - l) / 2;
		if (list[m] < target)
			l = m + 1;
		else
			r = m;
	}
	if (l < (int)list.size() && list[l] == target)
		return l + 1;
	return -1;
}

/* ===== 数学工具 ===== */
// greatest common divisor
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/* ===== 质数判断 (试除) ===== */
bool is_prime(ll n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (ll i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
	return true;
}

/* ===== BigInt（非负，常用竞赛版） ===== */
struct BigInt {
	static const int BASE = 1000000000;
	vector<int> d; // little-endian

	BigInt(long long x = 0) { *this = x; }

	BigInt &operator=(long long x) {
		d.clear();
		if (x == 0)
			return *this;
		while (x) {
			d.push_back((int)(x % BASE));
			x /= BASE;
		}
		return *this;
	}

	bool is_zero() const { return d.empty(); }

	void trim() {
		while (!d.empty() && d.back() == 0)
			d.pop_back();
	}

	void mul_int(int m) {
		if (is_zero() || m == 0) {
			d.clear();
			return;
		}
		long long carry = 0;
		for (size_t i = 0; i < d.size(); ++i) {
			long long cur = 1LL * d[i] * m + carry;
			d[i] = (int)(cur % BASE);
			carry = cur / BASE;
		}
		while (carry) {
			d.push_back((int)(carry % BASE));
			carry /= BASE;
		}
	}

	BigInt div_int(int v) const {
		BigInt q;
		if (is_zero())
			return q;
		q.d.assign(d.size(), 0);
		long long rem = 0;
		for (int i = (int)d.size() - 1; i >= 0; --i) {
			long long cur = d[i] + rem * BASE;
			q.d[i] = (int)(cur / v);
			rem = cur % v;
		}
		q.trim();
		return q;
	}

	friend bool operator<(const BigInt &a, const BigInt &b) {
		if (a.d.size() != b.d.size())
			return a.d.size() < b.d.size();
		for (int i = (int)a.d.size() - 1; i >= 0; --i) {
			if (a.d[i] != b.d[i])
				return a.d[i] < b.d[i];
		}
		return false;
	}

	friend bool operator>(const BigInt &a, const BigInt &b) {
		return b < a;
	}
	friend bool operator<=(const BigInt &a, const BigInt &b) {
		return !(b < a);
	}
	friend bool operator>=(const BigInt &a, const BigInt &b) {
		return !(a < b);
	}
	friend bool operator==(const BigInt &a, const BigInt &b) {
		return a.d == b.d;
	}
	friend bool operator!=(const BigInt &a, const BigInt &b) {
		return !(a == b);
	}

	string str() const {
		if (d.empty())
			return "0";
		string s = to_string(d.back());
		for (int i = (int)d.size() - 2; i >= 0; --i) {
			string t = to_string(d[i]);
			s += string(9 - (int)t.size(), '0') + t;
		}
		return s;
	}
};

/* ===== 二叉树基础 ===== */
template <typename T> struct TreeNode {
	T val;
	TreeNode *left, *right;
	TreeNode(T v = T()) : val(v), left(nullptr), right(nullptr) {}
};

// 按先序序列建树，空结点用 null_val 表示。
template <typename T>
TreeNode<T> *build_preorder(const vector<T> &seq, int &idx, const T &null_val) {
	if (idx >= (int)seq.size() || seq[idx] == null_val) {
		idx++;
		return nullptr;
	}
	TreeNode<T> *root = new TreeNode<T>(seq[idx++]);
	root->left = build_preorder(seq, idx, null_val);
	root->right = build_preorder(seq, idx, null_val);
	return root;
}

// 完全二叉树建树，常用于堆式下标题或淘汰赛分层题。
template <typename T>
TreeNode<T> *build_complete_tree(const vector<T> &seq, int idx = 1) {
	if (idx > (int)seq.size())
		return nullptr;
	TreeNode<T> *root = new TreeNode<T>(seq[idx - 1]);
	root->left = build_complete_tree(seq, idx * 2);
	root->right = build_complete_tree(seq, idx * 2 + 1);
	return root;
}

// 由前序和中序重建二叉树，要求结点值互不相同。
template <typename T>
TreeNode<T> *build_pre_in(const vector<T> &pre, int pl, int pr,
                          const vector<T> &in, int il, int ir,
                          const unordered_map<T, int> &pos) {
	if (pl > pr || il > ir)
		return nullptr;
	TreeNode<T> *root = new TreeNode<T>(pre[pl]);
	int k = pos.at(pre[pl]);
	int left_size = k - il;
	root->left = build_pre_in(pre, pl + 1, pl + left_size, in, il, k - 1, pos);
	root->right =
	    build_pre_in(pre, pl + left_size + 1, pr, in, k + 1, ir, pos);
	return root;
}

template <typename T>
TreeNode<T> *build_pre_in(const vector<T> &pre, const vector<T> &in) {
	if (pre.empty())
		return nullptr;
	unordered_map<T, int> pos;
	for (int i = 0; i < (int)in.size(); i++)
		pos[in[i]] = i;
	return build_pre_in(pre, 0, (int)pre.size() - 1, in, 0, (int)in.size() - 1,
	                    pos);
}

// 由中序和后序重建二叉树，要求结点值互不相同。
template <typename T>
TreeNode<T> *build_in_post(const vector<T> &in, int il, int ir,
                           const vector<T> &post, int pl, int pr,
                           const unordered_map<T, int> &pos) {
	if (il > ir || pl > pr)
		return nullptr;
	TreeNode<T> *root = new TreeNode<T>(post[pr]);
	int k = pos.at(post[pr]);
	int left_size = k - il;
	root->left = build_in_post(in, il, k - 1, post, pl, pl + left_size - 1, pos);
	root->right =
	    build_in_post(in, k + 1, ir, post, pl + left_size, pr - 1, pos);
	return root;
}

template <typename T>
TreeNode<T> *build_in_post(const vector<T> &in, const vector<T> &post) {
	if (in.empty())
		return nullptr;
	unordered_map<T, int> pos;
	for (int i = 0; i < (int)in.size(); i++)
		pos[in[i]] = i;
	return build_in_post(in, 0, (int)in.size() - 1, post, 0,
	                     (int)post.size() - 1, pos);
}

template <typename T> void preorder(TreeNode<T> *root, vector<T> &res) {
	if (!root)
		return;
	res.push_back(root->val);
	preorder(root->left, res);
	preorder(root->right, res);
}

template <typename T> void inorder(TreeNode<T> *root, vector<T> &res) {
	if (!root)
		return;
	inorder(root->left, res);
	res.push_back(root->val);
	inorder(root->right, res);
}

template <typename T> void postorder(TreeNode<T> *root, vector<T> &res) {
	if (!root)
		return;
	postorder(root->left, res);
	postorder(root->right, res);
	res.push_back(root->val);
}

template <typename T> vector<T> levelorder(TreeNode<T> *root) {
	vector<T> res;
	if (!root)
		return res;
	queue<TreeNode<T> *> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode<T> *cur = q.front();
		q.pop();
		res.push_back(cur->val);
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
	return res;
}

template <typename T> int tree_size(TreeNode<T> *root) {
	if (!root)
		return 0;
	return 1 + tree_size(root->left) + tree_size(root->right);
}

template <typename T> int tree_height(TreeNode<T> *root) {
	if (!root)
		return 0;
	return 1 + max(tree_height(root->left), tree_height(root->right));
}

template <typename T> int leaf_count(TreeNode<T> *root) {
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;
	return leaf_count(root->left) + leaf_count(root->right);
}

template <typename T> TreeNode<T> *bst_find(TreeNode<T> *root, const T &x) {
	if (!root || root->val == x)
		return root;
	if (x < root->val)
		return bst_find(root->left, x);
	return bst_find(root->right, x);
}

template <typename T> TreeNode<T> *bst_insert(TreeNode<T> *root, const T &x) {
	if (!root)
		return new TreeNode<T>(x);
	if (x < root->val)
		root->left = bst_insert(root->left, x);
	else if (x > root->val)
		root->right = bst_insert(root->right, x);
	return root;
}

template <typename T> TreeNode<T> *bst_min(TreeNode<T> *root) {
	if (!root)
		return nullptr;
	while (root->left)
		root = root->left;
	return root;
}

template <typename T> TreeNode<T> *bst_max(TreeNode<T> *root) {
	if (!root)
		return nullptr;
	while (root->right)
		root = root->right;
	return root;
}

template <typename T> TreeNode<T> *bst_erase(TreeNode<T> *root, const T &x) {
	if (!root)
		return nullptr;
	if (x < root->val) {
		root->left = bst_erase(root->left, x);
	} else if (x > root->val) {
		root->right = bst_erase(root->right, x);
	} else {
		if (!root->left) {
			TreeNode<T> *r = root->right;
			delete root;
			return r;
		}
		if (!root->right) {
			TreeNode<T> *l = root->left;
			delete root;
			return l;
		}
		TreeNode<T> *nxt = bst_min(root->right);
		root->val = nxt->val;
		root->right = bst_erase(root->right, nxt->val);
	}
	return root;
}

template <typename T> TreeNode<T> *lca(TreeNode<T> *root, const T &a, const T &b) {
	if (!root || root->val == a || root->val == b)
		return root;
	TreeNode<T> *left = lca(root->left, a, b);
	TreeNode<T> *right = lca(root->right, a, b);
	if (left && right)
		return root;
	return left ? left : right;
}

template <typename T>
TreeNode<T> *lca_bst(TreeNode<T> *root, const T &a, const T &b) {
	if (!root)
		return nullptr;
	if (a < root->val && b < root->val)
		return lca_bst(root->left, a, b);
	if (a > root->val && b > root->val)
		return lca_bst(root->right, a, b);
	return root;
}

template <typename T> void destroy_tree(TreeNode<T> *root) {
	if (!root)
		return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	delete root;
}

/* ===== 解决一个测试用例 ===== */
void solve() {
	int n;
	cin >> n;

	vector<int> left_child(n + 1), right_child(n + 1);
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		left_child[i] = l;
		right_child[i] = r;
	}

	queue<int> q;
	q.push(1);
	int depth = 0;
	while (!q.empty()) {
		int cnt = (int)q.size();
		depth++;
		while (cnt--) {
			int u = q.front();
			q.pop();
			if (left_child[u] != 0)
				q.push(left_child[u]);
			if (right_child[u] != 0)
				q.push(right_child[u]);
		}
	}

	cout << depth << '\n';
}

int main() {
	fastio;

	int T = 1;
	// cin >> T;  // 多组测试时取消注释
	while (T--)
		solve();

	return 0;
}
