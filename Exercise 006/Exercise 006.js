/*
  Find the difference between the sum of the squares of the
  one hundred natural numbers and the square of the sum.
  */

var helper = require('./helper.js'),

    result;

result = Array.apply(null, new Array(101))
  .reduce(function (a, _, i) {
    return [a[0] + i * i, a[1] + i];
  }, [0, 0])
  .reduce(function (a, b) {
    return Math.pow(b, 2) - a;
  });

helper(result);
