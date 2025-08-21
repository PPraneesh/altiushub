import axios from "axios";
import React, { useState } from "react";

interface SignUpFormData {
  username: string;
  email: string;
  password: string;
}

function SignUp() {
  const [signupData, setSignupData] = useState<SignUpFormData>({
    username: "",
    email: "",
    password: "",
  });

  const OnSubmit = () => {
    axios.post("http://localhost:8000/signup/", signupData).then((res) => {
      console.log("response", res);
      if (res.data.status) {
        alert("Creation success");
      }
    });
  };
  return (
    <div className="flex flex-col gap-2 border ">
      <div>
        <label htmlFor="username">Username</label>
        <input
          type="text"
          name="username"
          className="border"
          onChange={(e) => {
            setSignupData({ ...signupData, username: e.target.value });
          }}
        />
      </div>
      <div>
        <label htmlFor="email">Email</label>
        <input
          type="email"
          name="email"
          className="border"
          onChange={(e) => {
            setSignupData({ ...signupData, email: e.target.value });
          }}
        />
      </div>
      <div>
        <label htmlFor="password">Password</label>
        <input
          type="password"
          name="password"
          className="border"
          onChange={(e) => {
            setSignupData({ ...signupData, password: e.target.value });
          }}
        />
      </div>
      <input type="submit" value="submit" onClick={OnSubmit} />
    </div>
  );
}

export default SignUp;
