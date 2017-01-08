var sol = require('./solution.js');

var nums1 = [1, 2, 2, 1];
var nums2 = [2, 2];

var ret = sol.intersection(nums1, nums2);

console.log(ret);

nums1 = [12, 123, 123, 2, 12, 21, 12, 12, 12, 12, 12, 12, 12, 12, 1, 1, 12, 2, 2, 2, 12, 12, 2, 21, 21, 231, 32, 142, 123, 14, 41, 123, 241, 1];

ret = sol.intersection(nums1, nums1);

console.log(ret);
