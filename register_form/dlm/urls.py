from django.urls  import path

from . import views

urlpatterns = [
	path('',views.homePageView,name="home"),
	path('dashboard/',views.dashPageView,name="dashboard"),
	path('logout/',views.logout,name="logout"),
]