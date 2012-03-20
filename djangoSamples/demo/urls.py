from django.conf.urls.defaults import patterns, include, url

# Uncomment the next two lines to enable the admin:
# from django.contrib import admin
# admin.autodiscover()

urlpatterns = patterns('controllers',
    (r'^$', 'post.new'),
    # polls
    (r'^polls/$', 'polls.index'),
    (r'^polls/(?P<poll_id>\d+)/$', 'polls.detail'),
    # post
    (r'^post/new$', 'post.new'),
    (r'^post/show$', 'post.show'),
    # upload
    (r'^upload/new$', 'upload.new'),
    (r'^upload/create$', 'upload.create'),
    (r'^upload/redirect$', 'upload.redirect'),
    (r'^upload/show$', 'upload.show'),
    # Examples:
    # url(r'^$', 'demo.views.home', name='home'),
    # url(r'^demo/', include('demo.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    # url(r'^admin/', include(admin.site.urls)),
)
