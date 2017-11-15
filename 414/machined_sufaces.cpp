#include <iostream>
#include <vector>
using namespace std;

struct Rec
{
    vector<string> lines;       // digital image content
    unsigned n;                 // image row number
};

static int read_record(Rec& r);
static int process(const Rec& r);

static const int COLUM_NUM = 25;

int main(int argc, char* argv[])
{
    Rec r;
    int ret;
    while (ret = read_record(r)) {
        cout << process(r) << endl;
    }
    return 0;
}

int read_record(Rec& r)
{
    cin >> r.n;
    if (r.n == 0) {
        return 0;
    }

    string s;
    unsigned i = r.n;
    r.lines.clear();
    getline(cin, s);            // swallow the '\n'
    while (i--) {
        if (getline(cin, s)) {
            r.lines.push_back(s);
        } else {
            return 0;
        }
    }

    // assert(r.lines.size() == r.n);
    return r.n;
}

int process(const Rec& r)
{
    unsigned x_sum(0);
    unsigned space_sum(0);
    unsigned max_cx(0);         // max number of X in a certain line
    unsigned cx(0);             // count of X per line
    const vector<string>::size_type N = r.lines.size();
    for (vector<string>::size_type i = 0; i < N; ++i) {
        cx = 0;
        for (string::size_type j = 0; j < r.lines[i].size(); ++j) {
            if (r.lines[i][j] == 'X') {
                ++cx;
            }
        }
        max_cx = max(cx, max_cx);
        x_sum += cx;
    }
    space_sum = COLUM_NUM * N - x_sum;
    return space_sum - (COLUM_NUM - max_cx) * N;
}
