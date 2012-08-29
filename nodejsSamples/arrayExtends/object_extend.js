// http://stackoverflow.com/questions/3954438/remove-item-from-array-by-value
//

function extendArray(arrayConstructor) {
    arrayConstructor.prototype.remove= function(){
        var what, a= arguments, L= a.length, ax;
        while(L && this.length){
            what= a[--L];
            while((ax= this.indexOf(what))!= -1){
                this.splice(ax, 1);
            }
        }
        return this;
    }

    // http://ejohn.org/blog/javascript-array-remove/
    // Array Remove - By John Resig (MIT Licensed)
    Array.prototype.removeIndex = function(from, to) {
        var rest = this.slice((to || from) + 1 || this.length);
        this.length = from < 0 ? this.length + from : from;
        return this.push.apply(this, rest);
    };
}

exports.extendArray = extendArray;
