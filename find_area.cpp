#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int fuck() {
    int n;
    double area = 0, s = 0, m = 0;
    cin >> n;
    vector<double> x(n + 1);
    vector<double> y(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for (int i = 1; i <= n - 1; i++)
        s += x[i] * y[i + 1];

    s += x[n] * y[1];
    for (int i = 1; i <= n - 1; i++)
        m -= y[i] * x[i + 1];
    m -= y[n] * x[1];
    area = 0.5 * abs(s + m);
    cout.precision(12);
    cout << area << endl;
    return 0;
	
}

int main ()
{
    // fuck();
    int n;
    double area = 0, s = 0, m = 0;
    cin >> n;
	vector<pair<double, double>> points(n + 1);
	for (int i = 1; i <= n; i++)
        cin >> points[i].first >> points[i].second;
    
    for (pair<double, double> point : points) {
        cout << point.first << " " << point.second << endl;
    }


    for (int i = 1; i <= n - 1; i++)
        s += points[i].first * points[i + 1].second;

	s += points[n].first * points[1].second;
	for (int i = 1; i <= n - 1; i++)
        m -= points[i].second * points[i + 1].first;
	m -= points[n].second * points[1].first;
	area = 0.5 * abs(s + m);
	cout.precision(12);
    cout << area << endl;
	return 0;
    
}

