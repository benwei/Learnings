

(function($){
  Backbone.sync = function(method, model, success, error){ 
    success();
  }

  var Item = Backbone.Model.extend({
	    defaults: {
	      nick: 'hello',
	      desc: 'world'
	    }
  }); 

  var List = Backbone.Collection.extend({
    model: Item
  });

  var ItemView = Backbone.View.extend({
    tagName: 'li', // name of root tag in this.el

    events: { 
      'click span.swap':  'swap',
      'click span.delete': 'remove'
    },  

    initialize: function(){
      _.bindAll(this, 'render', 'unrender', 'swap', 'remove'); 

      this.model.bind('change', this.render);
      this.model.bind('remove', this.unrender);
    },
    render: function(){
      var itemview_html= _.template($("#item-view-template").html());
      
      $(this.el).html($(itemview_html({
	nick:this.model.get('nick'),
	desc:this.model.get('desc')
	})));
      return this; 
    },
    unrender: function(){
      $(this.el).remove();
    },
    swap: function(){
      var swapped = {
        nick: this.model.get('desc'), 
        desc: this.model.get('nick')
      };
      this.model.set(swapped);
    },
    remove: function(){
      this.model.destroy();
    }
  });

  var ListView = Backbone.View.extend({    
    el: $('body'), // attaches `this.el` to an existing element.

    events: {
	'click button#add': 'addItem'
    },

    initialize: function(){
       _.bindAll(this, 'render', 'addItem', 'appendItem'); // fixes loss of context for 'this' within methods

       this.collection = new List();
       this.collection.bind('add', this.appendItem); // collection event binder
       this.counter = 0;
       this.render(); // not all views are self-rendering. This one is.
       this.putItem('defaultname', 'defaultdata');
    },

    render: function(){
	var inputview_html= _.template($("#input-view-template").html());
 
	$(inputview_html({})).appendTo($(this.el));

	_(this.collection.models).each(function(item){
        appendItem(item);
      }, this);
    },

    putItem: function(name, msg){
      var item = new Item();
      item.set({
        nick: name,
        desc: msg
      });
      this.collection.add(item); // add item to collection; view is updated via event 'add'
    },

    addItem: function(){
      this.counter++;
      var item = new Item();
      var name = $("#name").val();
      var msg = $("#desc").val()
      item.set({
        nick: name,
        desc: msg
      });
      this.collection.add(item); // add item to collection; view is updated via event 'add'
    },

    appendItem: function(item) {
	var itemView = new ItemView({model: item})
	$('ul', this.el).append(itemView.render().el);
    }

  });

  var listView = new ListView();
})(jQuery);

