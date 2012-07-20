
foo=require('../src/foo')()

suite('foo', () ->
  suite('foo.sum', () ->
    test('sum(1,2) should equal 3', () ->
      a=foo.sum(1,2)
      a.should.equal(3)
    )
    test('sum(-2,2) should equal 0', () ->
      a=foo.sum(-2,2)
      a.should.equal(0)
    )
  )
)
