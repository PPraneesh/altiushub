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

response object

```
{
    "message": "User created successfully"
}
```

in the case of error

```
{
    "error": "UNIQUE constraint failed: auth_user.username"
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

REFRESH TOKEN ENDPOINT
POST: http://localhost:8000/api/token/refresh/
request object

```
{
    "refresh": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ0b2tlbl90eXBlIjoicmVmcmVzaCIsImV4cCI6MTc1NTg1MjI1OSwiaWF0IjoxNzU1NzY1ODU5LCJqdGkiOiJhODk2MjliNGU0ZmU0ZmM1YTI2N2Y3YzQwZmNiM2VlZCIsInVzZXJfaWQiOiIzIn0.vJ53-WfQNiClDjwDN_o-TQhGSEj8EmcxzxdQNl8SM4U"
}
```

response obj

```
{
    "access": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ0b2tlbl90eXBlIjoiYWNjZXNzIiwiZXhwIjoxNzU1NzY2NTk3LCJpYXQiOjE3NTU3NjYyOTcsImp0aSI6ImVmNDk1MmI2ZTZiNzQzODM4NTg0MDdiMWY3NDZiYmQzIiwidXNlcl9pZCI6IjMifQ.MJVP7e7jCjmUaoqsMvCGoQDF4xMoMunnxHzQ7S9z8GI"
}
```

TODO LIST
GET: http://localhost:8000/todo/
desc: gives all the todo lists associated with user

POST: http://localhost:8000/todo/

request object

```
{
    "title" : "backend Completion",
    "status" : false
}
```

UPDATING STATUS OF TODO LIST ITEM

POST: http://localhost:8000/todo/status/

request object

```
{
    "id" :2,
    "completed": true
}
```
