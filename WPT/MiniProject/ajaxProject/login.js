function signIn() {
    let xmlObj = new XMLHttpRequest();
    let uid = document.getElementById('emailId').value;
    let upass = document.getElementById('pssword').value;
    xmlObj.onload = function () {
        let userObj = JSON.parse(this.responseText);
        let flag = 0;
        for (let i of userObj) {
            if (i.userid === uid && i.userpass === upass) {
                flag = 1;
                break;
            }
        }
        if (flag === 1) {
            window.location.href = 'http://hematitecorp.com/';
            window.alert("Login Successfuly");
        } else {
            window.alert("Invalid Credentials.");
        }

    };
    xmlObj.open("GET", "http://localhost:8888/user");
    xmlObj.send();
}

function registerUser() {
    let upass1 = document.getElementById('inputPassword').value;
    let upass2 = document.getElementById('inputPassword2').value;
    if (upass1 === upass2) {
        let u = {
            userid: document.getElementById("inputEmail").value,
            userpass: document.getElementById("inputPassword").value
        }
        //object convert to json
        let udata = JSON.stringify(u);

        //xmlObject
        let xmlObj = new XMLHttpRequest();
        xmlObj.onload = function () {
            window.alert("Registration Successfull");

            document.getElementById("fName").value = "";
            document.getElementById("lName").value = "";
            document.getElementById("inputEmail").value = "";
            document.getElementById("inputPassword").value = "";
            document.getElementById("inputPassword2").value = "";

        };
        xmlObj.open("POST", "http://localhost:8888/user");
        xmlObj.send(udata);
        window.location.href = './login.html';
    }else{
        window.alert("Password is not matched");
    }
}
