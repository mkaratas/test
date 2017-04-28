Package.describe({
  name: 'fredcui:account',
  version: '0.0.1',
  // Brief, one-line summary of the package.
  summary: 'This module is used to add SMS check for account',
  // URL to the Git repository containing the source code for this package.
  git: '',
  // By default, Meteor will default to using README.md for documentation.
  // To avoid submitting documentation, set this field to null.
  documentation: 'README.md'
});

Package.onUse(function(api) {
  api.versionsFrom('1.4.2.3');
  api.use('ecmascript');
  api.mainModule('account.js');
});

Package.onTest(function(api) {
  api.use('ecmascript');
  api.use('tinytest');
  api.use('fredcui:account');
  api.mainModule('account-tests.js');
});
