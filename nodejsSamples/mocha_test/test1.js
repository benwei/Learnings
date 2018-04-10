const should = require('should')

function my_foo_inc(a) {
    if (a == null) return 1;
    return a+1;
}


describe('#inc', () => {
  it('should return varibale + 1', done => {
    a = my_foo_inc(1)
    a.should.equal(2)
    done()
  })
  it('should return 1 if input null', done => {
    a = my_foo_inc(null)
    a.should.equal(1)
    done()
  })
})
