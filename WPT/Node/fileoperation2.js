const { error } = require('console');
const fs = require('fs');

// //write asynchronously
// fs.writeFile("./asyncFile.txt","hello friends",(error,result)=>{
//     console.log("File write successfuly");
// });

// //read asynchronously
// fs.readFile("./asyncFile.txt","utf8",(error,result)=>{
//     console.log("data appended: "+result);
// });

// //append data asynchronously
// fs.appendFile("./asyncFile.txt","You all are my best friends.",(error,result)=>{
//     console.log("Data appended successfuly");
// });

// //write first and then read it
// fs.readFile("./asyncFile.txt","utf8",(error,result)=>{
//     fs.writeFile("./file.txt",result,(error,result)=>{
//         fs.appendFile("./file.txt","Be happy",(error,result)=>{

//         });
//     });
// });



// //remove asynchronously
// fs.unlink("./asyncFile.txt",(error,result)=>{
//     console.log("deleted successfully");
// });


// fs.mkdir("./NewDir",(error,result)=>{
//     fs.writeFile("./NewDir/newFile.txt","Hello friends",(error,result)=>{});
// });


fs.unlink("./NewDir/newFile.txt",(error,result)=>{
    fs.rmdir("./NewDir",(error,result)=>{});
});