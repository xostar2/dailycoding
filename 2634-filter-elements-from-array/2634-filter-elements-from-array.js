/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

 /* here it checks the given function that is it returning true or false   */
var filter = function(arr, fn) {

let filteredArr = [];

    for(let i=0; i<arr.length; i++){

if(fn(arr[i], i)){
filteredArr.push(arr[i])

    }}
    return filteredArr;
    
};