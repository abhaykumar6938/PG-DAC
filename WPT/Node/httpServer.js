const http = require('http');
const fs = require('fs');

let server = http.createServer((req,res)=>{
    if(req.url==='/'){
        res.write("Server get started");
        res.end();
    }else if(req.url==="/login"){
        fs.readFile("../../LoginPage/login.html");
    }
});
server.listen(5555,()=>{

});