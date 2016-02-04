'use strict';

var test = require('bindings')('test');

describe('when running async worker', function () {
    it('resolve the promise without jasmine timeout', function (done) {
        console.log('~Test started~');
        test(__dirname).then(function (argument) {
            console.log('~Resolved~');
            done();
        },done);
    });
});