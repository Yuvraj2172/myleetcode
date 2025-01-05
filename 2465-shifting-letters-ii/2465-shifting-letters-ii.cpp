class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
    vector<int> diff(n + 1, 0);

    // Apply the shifts to the difference array
    for (const auto& shift : shifts) {
        int start = shift[0], end = shift[1], direction = shift[2];
        int shiftValue = (direction == 1) ? 1 : -1;
        diff[start] += shiftValue;
        if (end + 1 < n) {
            diff[end + 1] -= shiftValue;
        }
    }

    // Compute the net shifts using prefix sum
    vector<int> netShifts(n, 0);
    int currentShift = 0;
    for (int i = 0; i < n; ++i) {
        currentShift += diff[i];
        netShifts[i] = currentShift;
    }

    // Apply the net shifts to the string
    for (int i = 0; i < n; ++i) {
        int originalIndex = s[i] - 'a';
        int newIndex = (originalIndex + netShifts[i]) % 26;
        if (newIndex < 0) {
            newIndex += 26; // Handle negative shifts
        }
        s[i] = 'a' + newIndex;
    }

    return s;
    }
};