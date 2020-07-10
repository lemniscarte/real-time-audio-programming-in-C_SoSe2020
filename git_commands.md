
# GIT COMMANDS 

Git has three main states that your files can reside in: committed, modified, and staged:

* Committed means that the data is safely stored in your local database.
* Modified means that you have changed the file but have not committed it to your database yet.
* Staged means that you have marked a modified file in its current version to go into your next commit snapshot.

## Basic Git Workflow 

* Create a new or checkout an existing repository.- Modify/add/delete files.- Either selectively stage just those changes you want to be part of your next commit or stage all.
* You do a commit, which takes the files as they are in the staging area and stores that snapshot permanently to your Git directory.
* If working with a remote, you push local changes to the remote.

## Initialize a local git and commit
New git.

`$ mkdir MY_PROJECT && cd MY_PROJECT`

`$ git init`


Create a file.

`$ touch README.md`


Add file to index.

`$ git add README.md`


Add all (added/changed) files at ones to index.

`$ git add .`


Commit the added file(s) to the HEAD

`$ git commit -m "README added - first commit"`


## Creating a repository
Create a remote repository via command line and/or in the Browser on github.com. Remote repository:

`$ curl -u 'funkerresch' https://api.github.com/user/repos -d '{"name":"realtimeaudioprogramming"}'`

*Note: You may need a password, depending on the repository setting*

## The easiest way to create local and remote repository
Create a remote repository online including readme.md
Copy the link to the repository

`$ cd TO/LOCATION/WHERE/YOU/WANT/TO/SAVE/YOUR/LOCAL/REPOSITORY` 

`$ git clone https://github.com/LINKTOYOURREMOTEREPOSITORY`


## Staging files
Stage everything according to the local directory structure including new, modified and deleted files):

`$ git add –A`

Stage everything without deleted files:

`$ git add .`

Stage modified and deleted, without new files:

`$ git add -u`

Stage single files and folders:

`$ git add <filename> git add <foldername>`
	
## Commit	
Commit all staged files to local repository:

`$ git commit –m “First Commit”` (-m for commit message)
	
## Connect your local git with a server or add a remote to the local repository
Connect local repo with server (remote git name must be same as local git name).

`$ git remote add origin <server_address>`

`$ git remote add origin https://github.com/audio-communication-group/real-time-audio-programming-in-C_SoSe2020`

Change remote URL.

`$ git remote set-url origin <server_address>`

*Note: Repository names online and local must be the same*

Show your remote connection.

`$ git remote -v`



Till now, all is proceeded locally.
Loading the files to the server will make them available for others.

`$ git push origin master`


At beginning your work, get a fresh copy first.

`$ git pull`

## Push, pull and clone
Push to remote and link local repository with remote so git pull can be used without arguments:

`$ git push –u origin master` (-u links the local repository with the remote)

origin is an alias for the remote, only needed once, after that simply use:
`$ git push`

Download the head of the remote and merges it with your local repository:

`$ git pull`

Download and inits a new local repository from PATH/TO/REPOSITORY:

`$ git clone PATH/TO/REPOSITORY`

## Git status information to show aliases of your remote server:
`$ git remote –v`

Get general status information:

`$ git status`

List the commit history:

`$ git log`

General information about HEAD:

`$ git show HEAD`


## Gitignore
Create `.gitignore` file with 

`$ touch .gitignore` (under linux and osx it will be invisible) in the Root directory of your repository.

Use nano vi or emacs for editing: 
`$ nano .gitignore` Add, for example, the line
`*.html` and save the file.
Now all html files will be excluded from staging

## Branches I
Its good practice to have at least this minimal structure: MASTER <---> DEVELOPMENT <---> FEATURE.

  * The master branch should always contain working minor versions
  * The development branch holds the working new features, that are not published or merged into the master branch
  * The feature branch(es) are holding separated features under development


`$ git branch DEVELOPMENT_BRANCH`

`$ git branch FEATURE_BRANCH`


Show all branches.

`$ git branch -a -v`


Then make a branch to work with.

`$ git checkout -b WORKING_COPY`


Double check where you are.

`$ git status`


After your work all is fine and you may wish to merge into your `FEATURE_BRANCH`, first switch into your branch you wish to merge in.

`$ git checkout FEATURE_BRANCH`

Show changes.

`$ git diff FEATURE_BRANCH WORKING_COPY`

Merge WORKING_COPY into FEATURE_BRANCH.

`$ git merge WORKING_COPY`


If you want, you can delete your WORKING_COPY.

`$ git branch -d WORKING_COPY`

Delete local branch (force).

`$ git branch -D WORKING_COPY`

Delete the remote WORKING_COPY.

`$ git push origin --delete WORKING_COPY`

Check if there are more branches that are not merged already.

`$ git branch --no-merged`

## Branches II
To check out commit id and create a new branch of it.

`$ git checkout -b <NEW BRANCH> <COMMITID>`
	
To check out X commits before HEAD and create new branch of it.

`$ git checkout –b <NEW BRANCH> HEAD~X`
	
Get information about X commits before HEAD.

`$ git show HEAD~X`

## Submodules
Add a submodule to your repository.

`$ git submodule add PATH/TO/SUBMODULE`

Remove submodule from your repository.


```
$ git submodule deinit PATH_TO_SUBMODULE
$ git rm PATH_TO_SUBMODULE
$ git commit-m "Removed submodule"
```

Remove submodule from directory.

`$ rm -rf .git/modules/PATH_TO_SUBMODULE`


## Removing  uncommited changes
In the case, you try want to remove all untracked changes in your BRANCH.

`$ git checkout -- *`

Or just the changes in one file.

`$ git checkout -- FILE_NAME`


## Removing  commited changes
First view history and get the hash of your commit(s).

`$ git log`

`$ git log --stat`

or

`$ git log --pretty=oneline`

or

`$ git log --pretty=format:"%h - %an, %ar : %s"`

or with showing branches and merges in ASCII.

`$ git log --pretty=format:"%h %s" --graph`

`$ git log --pretty=format:"%h - %an, %ar : %s"  --graph`



### Filter in time
`$ git log --since=1.weeks`

`$ git log --since=2.days`

`$ git log --since=3.hours`

`$ git log --since=40.minutes`

`$ git log --pretty=format:"%h - %an, %ar : %s"  --graph --since=2.days`


### Show the last commit
`$ git rev-parse --short HEAD` or 

`$ git show -s --format=%h` or

`$ git describe --always` for showing short hash

`$ git rev-parse HEAD` or 

`$ git show -s --format=%H` for full hash


### You can make a own shortcut(s)
`$ git config --global alias.lastcommit "rev-parse HEAD"`

`$ git lastcommit`

### Reset vs. revert
With `reset` all later commit(s) will be gone, you can just go back - history will be changed (use on private branch only).

`$ git reset HASH_OF_AN_EARLIER_COMMIT` 


With `revert` you will make a new commit with the content of the earlier commit, all commits in between stay saved (recommended) - history not changed (good practice on public branch).

`$ git revert HASH_OF_AN_EARLIER_COMMIT` 

You can use relative address with HEAD or a commit hash.

### Now go back to an earlier commit
Choose your commit, copy the hash.

`$ git log --pretty=format:"%h - %an, %ar : %s"  --graph`


### Just switching without making any changes
`$ git checkout HASH_OF_COMMIT_TO_GO_BACK`


### Reset
`$ git checkout BRANCH`

`$ git reset HEAD~1` resets to the grandparent of the HEAD commit

`$ git reset HASH`   resets to the hash's commit

### Revert
`$ git checkout BRANCH`

`$ git revert HEAD^1` reverts to the parent of the HEAD commit

`$ git revert HASH`   reverts to the hash's commit


### Stash
Situation: The phone rings in the middle of your work and you are told you need to make some corrections in another branch. If you are not ready to commit your current work now, you can stash it.

`$ git stash`

Later, you can return to your work.

`$ git stash pop`


If you don'nt remember, you can list your stashes.

`$ git stash list`


Show diffs of your stashes.

`$ git stash show --patch`

Of course you can make a new branch from stash too.

`$ git stash branch NEW_BRANCH_NAME stash@{1}`

If you want discard a stash you can drop it ...

`$ git stash drop stash@{1}`

... or remove all stashes at ones.

`$ git stash clear`


### Rebase
Situation: While you're working on your feature, the master is updated by someone else.
Now you want to integrate the new master updates into your feature branch.
With `rebase` you can move branches and merge them in one step into a new base to make the history linear again. 

*Note: This will change the history and should only be done at your local branch*

`$ git rebase MASTER_BASE`


If you running in conflicts, use 

`$ git mergetool` to fix them.




to be continued...



useful link: https://rogerdudler.github.io/git-guide/index.de.html














