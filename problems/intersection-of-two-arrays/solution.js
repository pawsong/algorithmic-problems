/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    if ( nums1.length > nums2.length ) {
        return intersection(nums2, nums1);
    }

    var solution = [];
    var hashTbl = {};

    for ( var i = 0; i < nums1.length; i++ ) {
        hashTbl[ nums1[i] ] = true;
    }

    for ( var j = 0; j < nums2.length; j++ ) {
        if ( nums2[j] in hashTbl && hashTbl[ nums2[j] ] === true ) {
            hashTbl[nums2[j]] = false;
            solution.push( nums2[j] );
        }
    }

    return solution;
};

module.exports = {
    intersection: intersection
};
