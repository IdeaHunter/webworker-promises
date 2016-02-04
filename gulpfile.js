'use strict';

let gulp = require('gulp');
let jasmine = require('gulp-jasmine');

gulp.task('test', function () {
    return gulp.src("test.spec.js")
        .pipe(jasmine({verbose:true}));
});
