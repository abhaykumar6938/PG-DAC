const path = require('path');
const os= require('os');

console.log(__dirname);
console.log(__filename);


console.log(path.basename(__dirname));

// return last portion of your path(path.basename)  and __filename return file name
console.log(path.basename(__filename));

//return the extension of your file
console.log(path.extname(__filename));

// check path is absolute or not (true/false)
console.log(path.isAbsolute(__filename));


//os 
console.log("===========OS===========");
console.log(os.arch());
console.log(os.type());
console.log(os.homedir());
console.log(os.hostname());
console.log(os.totalmem());
console.log(os.freemem());