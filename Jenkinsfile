pipeline {
    agent any
    stages {
        stage('Environment Check') {
            steps {
                sh 'gcc --version'
                sh 'make --version'
                sh 'cppcheck --version'
            }
        }
        
        stage('Static Analysis') {
            steps {
                // Run this before Build so it doesn't get skipped on failure
                sh 'cppcheck source/src/ > static-analysis-report.txt 2>&1 || true'
            }
        }

        stage('Build') {
            steps {
                dir('source') {
                    // Running without redirection to see errors in console
                    sh 'make clean && make'
                }
            }
        }
    }
    
    post {
        always {
            archiveArtifacts artifacts: '*.txt, source/build/*', allowEmptyArchive: true
        }
        cleanup {
            // This deletes the workspace folder on the server after archiving.
            // This is the "Remove it" fix you asked for—it ensures no old files remain.
            cleanWs()
        }
    }
}