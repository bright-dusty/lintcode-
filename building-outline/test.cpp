#include <vector>
#include <memory>
#include <set>
#include <map>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define _d() cout << __FUNCTION__ << ":" << __LINE__ << endl;fflush(stdout);

#define ENUMERATE(x) \
	for (auto iter=x.begin(); iter != x.end(); iter++)
class Solution {
public:
    /*
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int>> _buildingOutline(vector<vector<int>> &buildings ) {
        // write your code here
		set<int> _positions;
		vector <int> positions;
		vector<vector<int>> outline;

		ENUMERATE(buildings) {
			_positions.insert((*iter)[0]);
			_positions.insert((*iter)[1]);
		}

		size_t index = 0;
		ENUMERATE(_positions) {
			positions.push_back(*iter);
		}
		int* intervals = new int[positions.size()-1]();
		
		ENUMERATE(buildings) {
			size_t start = lower_bound(positions.begin(), positions.end(), (*iter)[0]) - positions.begin();
			size_t length = lower_bound(positions.begin(), positions.end(), (*iter)[1]) - positions.begin() - start;
			while (length--) {
				if ((*iter)[2] > intervals[start])
					intervals[start] = (*iter)[2];
				start ++;
			}
		}

		int height = 0;
		ENUMERATE(positions) {
			size_t index = iter - positions.begin();
			if (index == positions.size() - 1)
				break;
			if (!outline.empty() && outline[outline.size()-1][2] == intervals[index]) {
				outline[outline.size()-1][1] = positions[index+1];
				continue;
			}
			if (intervals[index])
				outline.push_back(vector<int>({positions[index], positions[index+1], intervals[index]}));
		}

		delete [] intervals;
		return outline;
    }
	vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
		if (buildings.empty())
			return buildings;
		vector<vector<int>> _buildings;
		int merge_interval = int(log(buildings.size())) + 1;
		ENUMERATE (buildings) {
			_buildings.push_back(*iter);
			if ((iter - _buildings.begin()) % merge_interval == 1)
			_buildings = _buildingOutline(_buildings);
		}
		_buildings = _buildingOutline(_buildings);
		return _buildings;
	}
};

int main() {
	vector<vector<int>> buildings ;
	
	int s, e, h,
		_s, _e, _h;
	while (true) {
		scanf("[%d,%d,%d],", &s, &e, &h);
		if (s == _s && e == _e && h == _h)
			break;
		_s = s; _e = e; _h = h;
		buildings.push_back(vector<int>({s, e, h}));
	}
	auto outline = Solution().buildingOutline(buildings);
	ENUMERATE(outline) {
		//cout << (*iter)[0] << " " << (*iter)[1] << " " << (*iter)[2] << endl;
	}
}
