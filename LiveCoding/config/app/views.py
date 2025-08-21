from django.shortcuts import render
from .models import Todo
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework.permissions import IsAuthenticated
from django.contrib.auth.models import User
from django.contrib.auth.models import User
from .serializer import TodoSerializer

class HelloView(APIView):
    permission_classes = (IsAuthenticated, )

    def get(self, request):
        content = {'message': 'Hello, GeeksforGeeks'}
        return Response(content)
    
class SignUp(APIView):

    def post(self,request):
        username = request.data.get('username')
        password = request.data.get('password')
        email = request.data.get('email')

        # input validation
        if not username or not password or not email:
            return Response({'error': 'All fields are required'}, status=400)
        
        try: 
            user = User.objects.create_user(username, email, password)
            user.save()
        except Exception as e:
            return Response({'error': str(e)}, status=400)
        return Response({'message': 'User created successfully'}, status=201)


class List(APIView):
    permission_classes = (IsAuthenticated, )

    def get(self, request):
        todos = Todo.objects.filter(username=request.user.username)
        serializer = TodoSerializer(todos, many=True)
        return Response(serializer.data)

    def post(self, request):
        serializer = TodoSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save(username=request.user.username)
            return Response(serializer.data, status=201)
        return Response(serializer.errors, status=400)

# Marks as completed feature
class TodoOperations(APIView):
    permission_classes = (IsAuthenticated, )

    def post(self,request):
        if(request.data.get("completed")): 
            id = request.data.get("id")
            item = Todo.objects.filter(id = id)
            if(request.user.username == item[0].username):
                item.update(completed = request.data.get("completed"))
                return Response({"status":True},status = 200)
            else:
                return Response({"status":False},status = 403)

        return Response({"status":False},status = 400)

