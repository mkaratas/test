/**
 * Created by fred on 17-2-20.
 */
var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
    // res.render('index', { title: 'Express' });
    console.log("req: ", req);
});

module.exports = router;