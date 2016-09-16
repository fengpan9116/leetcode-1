/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        // Fuck you leetcode!
        if (points.empty()) return 0;
        unordered_map<double, int> slope_to_count;
        int max_ = 1; double slope = INT_MAX;
        for (int i = 0; i < points.size(); i++){
            slope_to_count.clear();
            int duplicates = 0;
            for (int j = i+1; j < points.size(); j++){
                // Test if point is a duplicate
                if (points[i].x == points[j].x && points[i].y == points[j].y) duplicates++;
                // Calculate slope
                else {
                    slope = points[i].x == points[j].x ? INT_MAX : (double)(points[i].y-points[j].y) / (double)(points[i].x-points[j].x);
                    if (slope_to_count.count(slope) > 0) slope_to_count[slope]++;
                    else slope_to_count[slope] += 2;
                }
            }
            // Update max
            for (auto i : slope_to_count)
                max_ = max(max_, i.second+duplicates);
            if (slope_to_count.size() == 0) max_ = max(max_, duplicates+1);
        }
        return max_;
    }
};