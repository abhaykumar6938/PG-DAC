const fs = require('fs');

//write=> if file not exists create and write data. if exists then rewrite.
fs.writeFileSync("./file.txt","Hello my friends how are you?");

//fs.append
fs.appendFileSync("./file.txt","hello this is my line 2.");

//read file

let data= fs.readFileSync("./file.txt");

console.log("data: "+data);


//remove file
fs.unlinkSync("./file.txt");