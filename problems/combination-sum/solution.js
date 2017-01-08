/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    return dfs_backtrack( [], candidates, 0, target );
};

function dfs_backtrack( partialSolution, candidates, idx, target ) {
    var solution = [];

    var sum = 0;
    for ( var i = 0; i < partialSolution.length; i++ ) {
        sum += partialSolution[i];
    }

    if ( sum == target ) {
        solution.push(partialSolution);
    }
    else if ( idx - 1 < candidates.length ) {
        var k = 0;
        while ( k * candidates[idx] <= target - sum ) {
            var newPartialSolution = partialSolution.slice(0);
            for ( var j = 0; j < k; j++ ) {
                newPartialSolution.push( candidates[idx] );
            }
            solution = solution.concat( dfs_backtrack( newPartialSolution, candidates, idx + 1, target ) );
            k++;
        }
    }

    return solution;
};

module.exports = {
    combinationSum: combinationSum
};
