module.exports = (ma, mb) ->
  that = {}
  that.sum = (a, b) ->
    return (ma || 0) + (mb || 0) + a + b
  return that
