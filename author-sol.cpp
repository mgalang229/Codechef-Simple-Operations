#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);                         
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		string r;
		cin >> r;
		long long gaps = 0;
		long long l = 0;
		long long islands = 0;
		bool checker = false;
		vector<long long> all_gaps;
		for (int i = 0; i < (int) s.size(); i++) {
			if (s[i] == r[i]) {
				// count the elements in the gap (equal characters)
				if (checker) {
					gaps++;
				}
			} else {
				// suppose, characters from a <= i <= b, are not equal (s[a] != r[a], s[a + 1] != r[a + 1], ..., s[b] != r[b])
				// l = total no. of all unequal characters in all segments
				// islands = total no. of segments that contain unequal characters
				if (!checker) {
					islands++;
				}
				checker = true;
				l++;
				if (gaps > 0) {
					islands++;
					all_gaps.push_back(gaps);
					gaps = 0;
				}
			}
		}
		// sort the all the no. of gaps in non-decreasing order
		// include the gaps between islands one-by-one and calculate the final answer everytime
		// a segment of gaps is added in the total no. of unequal characters (l)
		// note: don't forget to decrement the total no. of islands everytime we bridge the gap
		sort(all_gaps.begin(), all_gaps.end());
		long long ans = islands * l;
		for (auto& e : all_gaps) {
			l += e;
			islands--;
			ans = min(ans, l * islands);
		}
		cout << ans << '\n';
	}
	return 0;
}
