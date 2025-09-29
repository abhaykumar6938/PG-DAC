import prompt from 'prompt';
import chalk from 'chalk';

let succes=chalk.bold.green.italic.underline;
let fails=chalk.bold.red.italic.underline;
prompt.start();
prompt.get(['username','password'],function(err,result){
    if(result.username==='abhay' && result.password==='123'){
        console.log(succes("Login successfully"));
    }else{
        console.log(fails("Invalid credentials"));
    }
});
