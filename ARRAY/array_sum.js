const arr = [1,2,3,4];

// Step - 1
let sum = 0;
for(let i = 0; i < arr.length; ++i)
  sum += i;

// Step - 2
sum = arr.reduce((sum, num) => sum + num);
