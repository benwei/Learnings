define([], function() {
  return {
    say: function(max) {
        for (var person_id=0; person_id < max; person_id ++) {
            var msg;
            var question = 'How are you';

            if (person_id % 2== 0) {
            msg = question;
            } else {
            msg = 'I am fine.' + question ;
            }
            
            var strWords = msg + ', guy' + person_id + '?';
            console.log(strWords);
        }
    }
  }
});
