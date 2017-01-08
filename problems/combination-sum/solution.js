/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
const combinationSum = ( candidates, target ) => dfs_backtrack( [], candidates, 0, target );

function dfs_backtrack( partialSolution, candidates, idx, target ) {
    let solution = [];

    const sum = partialSolution.reduce(( acc, cur ) => acc + cur, 0);

    if ( sum === target ) {
        solution.push(partialSolution);
    }
    else if ( idx - 1 < candidates.length ) {
        let k = 0;
        while ( k * candidates[idx] <= target - sum ) {
            const newPartialSolution = partialSolution.slice(0);
            for ( let j = 0; j < k; j++ ) {
               newPartialSolution.push( candidates[idx] );
            }
            solution = solution.concat( dfs_backtrack( newPartialSolution, candidates, idx + 1, target ) );
            k++;
        }
    }

    return solution;
};

exports.combinationSum = combinationSum;
