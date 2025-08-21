SIGNUP
POST : http://localhost:8000/signup/

request object

```
{
    "username" : "pratheek",
    "password" : "hey",
    "email": "pratheek@gmail.com"
}
```

LOGIN
POST: http://localhost:8000/api/token/

request object

```
{
    "username" : "pratheek",
    "password" : "hey"
}
```

TODO LIST
GET: http://localhost:8000/todo/
desc: gives all the todo lists associated with user
