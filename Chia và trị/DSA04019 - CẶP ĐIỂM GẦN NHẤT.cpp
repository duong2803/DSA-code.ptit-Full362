
// created: 2023-05-26 18:09:25
// author: Nguyen Tung Duong


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point{
	ll x, y;

	bool operator<(const Point &p){
		if(x != p.x) return x < p.x;
		return y < p.y;
	}
};

ll dist(Point a, Point b){
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		vector<Point> points(n);
		for(int i = 0; i < n; ++i)
			cin >> points[i].x >> points[i].y;
		
		auto cmp = [](Point p1, Point p2){
			if(p1.y != p2.y) return p1.y < p2.y;
			return p1.x < p2.x;
		};
		set<Point, decltype(cmp)> st(cmp);
		
		sort(points.begin(), points.end());		
		ll res = dist(points[0], points[1]);
		for(Point p : points){
			
			ll d = sqrt(res);
			Point tmp = {-10000, p.y - d};	
			while(true){
				auto it = st.upper_bound(tmp);
				if(it == st.end()) break;
				tmp = *it;
				if(tmp.y > p.y + d) break;
				if(tmp.x < p.x - d){
					st.erase(it);
					continue;
				}
				res = min(res, dist(tmp, p));
			}
			st.insert(p);
		}	
		cout << fixed << setprecision(6) << sqrt(res) << '\n';
		
	}

	return 0;
}

