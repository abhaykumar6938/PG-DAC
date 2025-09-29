import validator from 'validator'
let myemail="abhay@gmail.com";
console.log(validator.isEmail(myemail));

console.log(validator.isEmpty(myemail));
