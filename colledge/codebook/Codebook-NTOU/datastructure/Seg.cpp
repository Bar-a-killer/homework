struct Seg {
#define cl(x) (x << 1)
#define cr(x) (x << 1) + 1
    int _n;
    vector<int> f, tag;
    vector<int> arr;
    int base;

    Seg(int n) : _n(n), f(4 * n), tag(4 * n) {}

    Seg(vector<int> a, int b) {
        _n = a.size();
        f.resize(4 * _n + 1, 0);
        tag.resize(4 * _n + 1, 0);
        arr.resize(_n);
        for (int i = 0; i < _n; i++) {
            arr[i] = a[i];
        }
        base = b;
        build(1, base, _n - 1 + base);
    }

    void build(int id, int l, int r) {
        if (l == r) {
            f[id] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(cl(id), l, mid);
        build(cr(id), mid + 1, r);
        pull(id, l, r);
    }

    void pull(int id, int l, int r) {
        int mid = (l + r) >> 1;
        push(cl(id), l, mid);
        push(cr(id), mid + 1, r);
        f[id] = f[cl(id)] + f[cr(id)];
    }

    void push(int id, int l, int r) {
        if (tag[id]) {
            f[id] += tag[id] * (r - l + 1);
            if (l != r) {
                tag[cl(id)] += tag[id];
                tag[cr(id)] += tag[id];
            }
            tag[id] = 0;
        }
    }

    void update(int id, int l, int r, int x, int v) {
        if (l == r) {
            f[id] = v;
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid) update(cl(id), l, mid, x, v);
        if (mid < x)  update(cr(id), mid + 1, r, x, v);
        pull(id, l, r);
    }

    void update(int id, int l, int r, int ql, int qr, int v) {
        push(id, l, r);
        if (ql <= l and qr >= r) {
            tag[id] += v;
            return;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid) {
            update(cl(id), l, mid, ql, qr, v);
        }
        if (qr > mid) {
            update(cr(id), mid + 1, r, ql, qr, v);
        }
        pull(id, l, r);
    }

    int query(int id, int l, int r, int sl, int sr) {
        push(id, l, r);
        if (sl <= l and sr >= r) {
            return f[id];
        }
        int res = 0;
        int mid = (l + r) >> 1;
        int ll = 0;
        int rr = 0;
        if (sl <= mid) {
            ll = query(cl(id), l, mid, sl, sr);
        }
        if (sr > mid) {
            rr = query(cr(id), mid + 1, r, sl, sr);
        }
        res = ll + rr;
        return res;
    }
};