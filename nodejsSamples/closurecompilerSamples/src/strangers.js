define(['talk'], function(talk) {

  return {
    hi: function(leading) {
        for (var person_id=0; person_id < 10; person_id ++) {
            var strHi;

            if (person_id % 2== 0) {
            strHi = 'Hi';
            } else {
            strHi = leading;
            }

            var letsrun = strHi + ', guy' + person_id + ', let\'s go with closure compiler.';
            console.log(letsrun);
        }
        talk.say(10);
    }
  }
});
