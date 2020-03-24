#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
struct Point {
	int x, y;
};
int n;
bool cmp(struct Point& a, struct Point& b) {     //按照x坐标从小到大排序
	return a.x < b.x;
}
bool cmp2(struct Point& a, struct Point& b) {     //按照y坐标从小到大排序
	return a.y < b.y;
}
double Dis(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
/*----------以下为最近对问题算法----------*/ 
double ClosestPoint(vector<Point> points, int left, int right) {
	if (right - left < 2)return 0x3f3f3f3f;
	if (right - left == 2) {
		return Dis(points[left], points[right - 1]);
	}
	if (right - left == 3) {
		double d1 = Dis(points[left], points[right - 1]);
		double d2 = Dis(points[left], points[right - 2]);
		double d3 = Dis(points[right - 2], points[right - 1]);
		return min(d1, min(d2, d3));
	}
	int mid = (right + left) / 2;
	int mm = points[mid].x;
	double dl = ClosestPoint(points, left, mid);      //左边区域最短距离
	double dr = ClosestPoint(points, mid, right);     //右边区域最短距离
	double minn = min(dl, dr);
	vector<Point>v;
	for (int i = left; i < mid; ++i) {
		if (mm - points[i].x <= minn)
			v.push_back(points[i]);
	}
	for (int i = mid; i < right; ++i) {
		if (points[i].x - minn <= mm)
			v.push_back(points[i]);
	}
	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < v.size(); ++i) {            //处理分隔线两边的点
		for (int j = i+1; j < v.size(); ++j) {
			if (abs(v[i].y - v[j].y) < minn) {
				double d = Dis(v[i], v[j]);
				if (d < minn) minn = d;
			}
			else {
				break;
			}
		}
	}
	return minn;
}
/*----------以上为最近对问题算法----------*/ 
int main() {
	vector<Point>points;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		Point point;
		scanf("%d %d", &point.x, &point.y);
		points.push_back(point);
	}
	sort(points.begin(), points.end(), cmp);      //按照x坐标从小到大排序
	printf("%.2f\n", ClosestPoint(points, 0, n));
}
