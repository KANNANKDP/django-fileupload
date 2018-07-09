from django.shortcuts import render,redirect

from django.http import HttpResponse
# Create your views here.
from .models import Document
from register import models
from django.contrib import messages

def homePageView(request):
	return render(request,'home.html',{})

def dashPageView(request):
	if(request.session.has_key('log_in')==True):
		if(request.session['log_in']==True):
			# return HttpResponse('session is active now...')
			# data = models.UserDetail.objects.all()
			# user_data = {
			# 	'users' : data
			# 	,'name' : request.session['name']
			# }
			# return render(request,'dashboard.html',user_data)
			if(request.method == 'POST'):
					newdoc = Document(docfile = request.FILES['myfile'])
					newdoc.save()
					messages.success(request, 'File Uploaded successfully...')
      				#return HttpResponseRedirect('/dashboard/'+in_username)
					return redirect('/dashboard/')
					
			documents = Document.objects.all()

			doc_data = {
				'documents' : documents,
				'name' : request.session['name']
			}

			return render(request,'dashboard.html',doc_data)

	elif(request.session.has_key('log_in')==False):
		return redirect('/login/')

	else:
		return redirect('/login/')

def logout(request):
	if(request.session.has_key('log_in')==True):
		del request.session['log_in']
		del request.session['name']
		request.session.flush()
		request.session.modified = True
		return redirect('/login/')