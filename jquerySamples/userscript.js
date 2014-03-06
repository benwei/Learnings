
// ==UserScript==
// @name           Add jQuery
// @namespace      http://people.ischool.berkeley.edu/~npdoty
// @description    Insert the jQuery script so that we can run commands in Firebug
// @include        http://*
// @include        https://*
// ==/UserScript==
// Add jQuery to any (or every) webpage
// http://blogs.ischool.berkeley.edu/i290-04f09/2009/09/12/add-jquery-to-any-or-every-webpage/

var GM_JQ = document.createElement('script');
GM_JQ.src = 'http://ajax.googleapis.com/ajax/libs/jquery/1.3.2/jquery.min.js';
GM_JQ.type = 'text/javascript';
document.getElementsByTagName('head')[0].appendChild(GM_JQ);


