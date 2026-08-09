int trap(vector<int>& height) {
    int n = height.size();
    int water = 0;

    for(int i = 0; i < n; i++) {

        int leftMax = 0;
        int rightMax = 0;

        for(int j = 0; j <= i; j++)
            leftMax = max(leftMax, height[j]);

        for(int j = i; j < n; j++)
            rightMax = max(rightMax, height[j]);

        water += min(leftMax, rightMax) - height[i];
    }

    return water;
}