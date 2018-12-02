/* global self */
(function () {
  var root = (typeof self === 'object' && self.self === self && self) ||
      (typeof global === 'object' && global.global === global && global) ||
      this || {}

  var util = {
    extend: function (target) {
      for (var i = 1; i < arguments.length; i++) {
        for (var prop in arguments[i]) {
          if (arguments[i].hasOwnProperty(prop)) {
            target[prop] = arguments[i][prop]
          }
        }
      }
      return target
    },
    addEvent: function (element, type, fn) {
      if (document.addEventListener) {
        element.addEventListener(type, fn, false)
        return fn
      } else if (document.attachEvent) {
        var bound = function () {
          return fn.apply(element, arguments)
        }
        element.attachEvent('on' + type, bound)
        return bound
      }
    },
    indexOf: function (array, item) {
      if (array.indexOf) {
        return array.indexOf(item)
      } else {
        var res = -1
        for (var i = 0; i < array.lenth; i++) {
          if (array[i] === item) {
            res = i
            break
          }
        }
        return res
      }
    },
    isValidListener: function (listener) {
      if (typeof listener === 'function') {
        return true
      } else if (listener && typeof listener === 'object') {
        return util.isValidListener(listener.listener)
      } else {
        return false
      }
    }
    /*
    getViewPortSizeHeight: function() {
      var w = window
      if (w.innerWidth != null)
        return w.innerHeight
      //标准模式
      var d = document
      if (document.compatMode === 'CSS1Compat') {
        return d.documentElement.clientHeight
      } else {
        //怪异模式
        return d.body.clientHeight
      }
    },
    getScrollOffsetTop: function() {
      var w = window
      if (w.pageXOffset != null)
        return w.pageYOffset
      var d = w.document
      if (document.compatMode === 'CSS1Compat') {
        return d.documentElement.scrollTop
      } else {
        return d.body.scrollTop
      }
    },
    */
  }

  function moduleName (options) {
    this.options = util.extend({}, this.constructor.defaultOptions, options)
    this.handlers = {}
    // this.init()
  }
  moduleName.VERSION = '1.0.0'
  moduleName.defaultOptions = {}

  if (typeof exports !== 'undefined' && !exports.nodeType) {
    if (typeof module !== 'undefined' && !module.nodeType && module.exports) {
      exports = module.exports = moduleName
    }
    exports = moduleName
  } else {
    root.moduleName = moduleName
  }
}())
