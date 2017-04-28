// Import Tinytest from the tinytest Meteor package.
import { Tinytest } from "meteor/tinytest";

// Import and rename a variable exported by account.js.
import { name as packageName } from "meteor/fredcui:account";

// Write your tests here!
// Here is an example.
Tinytest.add('account - example', function (test) {
  test.equal(packageName, "account");
});
